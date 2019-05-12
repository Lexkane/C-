#include <iostream>
#include <optional>
#include <ranges>   

using namespace std;

template<Semiregular T>
struct maybe_view : view_interface<maybe_view<T>> {
  maybe_view() = default;
  maybe_view(T t) : data_(std::move(t)) {
  }
  T const *begin() const noexcept {
    return data_ ? &*data_ : nullptr;
  }
  T const *end() const noexcept {
    return data_ ? &*data_ + 1 : nullptr;
  }
private:
  optional<T> data_{};
};

inline constexpr auto for_each =
  []<Range R,
     Iterator I = iterator_t<R>,
     IndirectUnaryInvocable<I> Fun>(R&& r, Fun fun)
        requires Range<indirect_result_t<Fun, I>> {
      return std::forward<R>(r)
        | view::transform(std::move(fun))
        | view::join;
  };

// "yield_if" берёт bool и значение, 
inline constexpr auto yield_if =
  []<Semiregular T>(bool b, T x) {
    return b ? maybe_view{std::move(x)}
             : maybe_view<T>{};
  };

int main() {
  using view::iota;
  auto triples =
    for_each(iota(1), [](int z) {
      return for_each(iota(1, z+1), [=](int x) {
        return for_each(iota(x, z+1), [=](int y) {
          return yield_if(x*x + y*y == z*z,
            make_tuple(x, y, z));
        });
      });
    });

    // Отображаем первые 10 троек
    for(auto triple : triples | view::take(10)) {
      cout << '('
           << get<0>(triple) << ','
           << get<1>(triple) << ','
           << get<2>(triple) << ')' << '\n';
  }
}

void printNTriples(int n)
{
    int i = 0;
    for (int z = 1; ; ++z)
        for (int x = 1; x <= z; ++x)
            for (int y = x; y <= z; ++y)
                if (x*x + y*y == z*z) {
                    printf("%d, %d, %d\n", x, y, z);
                    if (++i == n)
                        return;
                }
}

auto triples =
    for_each(iota(1), [](int z) {
        return for_each(iota(1, z+1), [=](int x) {
            return for_each(iota(x, z+1), [=](int y) {
                return yield_if(x*x + y*y == z*z,
                    make_tuple(x, y, z));
                });
            });
        });
		
		
		template<Semiregular T>
struct maybe_view : view_interface<maybe_view<T>> {
  maybe_view() = default;
  maybe_view(T t) : data_(std::move(t)) {
  }
  T const *begin() const noexcept {
    return data_ ? &*data_ : nullptr;
  }
  T const *end() const noexcept {
    return data_ ? &*data_ + 1 : nullptr;
  }
private:
  optional<T> data_{};
};
inline constexpr auto for_each =
  []<Range R,
     Iterator I = iterator_t<R>,
     IndirectUnaryInvocable<I> Fun>(R&& r, Fun fun)
        requires Range<indirect_result_t<Fun, I>> {
      return std::forward<R>(r)
        | view::transform(std::move(fun))
        | view::join;
  };
inline constexpr auto yield_if =
  []<Semiregular T>(bool b, T x) {
    return b ? maybe_view{std::move(x)}
             : maybe_view<T>{};
  };
