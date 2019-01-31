
template <class etype>
class Queue
{
	class qnode
	{
	public:

		etype element;

		qnode *next;

		qnode(etype e = 0) : element(e), next(NULL)
		{ }
	};

	qnode *first;
	qnode *last;

public:

	Queue() : first(NULL), last(NULL)
	{ }

	inline bool isempty() const
	{
		return first == NULL;
	}

	void enQueue(const etype x);
	etype deQueue();
	void makeempty();
	etype display();
};
template <class etype>
void Queue <etype> ::enQueue(const etype x)
{
	if (isempty())
	{
		first = new qnode(x);
		last = first;
	}

	else
	{
		qnode *p = new qnode(x);

		last->next = p;
		last = last->next;
	}
}
template <class etype>
etype Queue<etype>::display()
{
	if (isempty())
		std::cout << "\n\nThe Queue is empty.";
{for (qnode *p = first; p != NULL; p = p->next)
		std::cout << p->element << " ";
}
	return 0;
}
template <class etype>
etype Queue<etype>::deQueue()
{
	etype x;
	qnode *p;
	if (!isempty())
	{
		x = first->element;

		p = first;
		first = first->next;

		delete p;

		return x;
	}
}
template <class etype>
void Queue<etype>::makeempty()
{
	while (!isempty())
		deQueue();
}


