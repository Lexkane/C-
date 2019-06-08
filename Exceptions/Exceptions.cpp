#include<string.h>
#include <stdio.h> 

using namespace std;


class Exc : public  exception {

              public:

                          Exc():exception() {}

                          Exc(const string& s):exception( s.c_str() ){}

                          virtual const char *what() const throw(){ return exception::what();}

             };

            class A {

                           int x;

                 public:

                           A(int i):x(i){ }



                           const string g(int i){if( i>x) throw Exc(":(");return "Ok";}

              };

             void F(){

                            try{ cout << (A(20)).g(10); }

                            catch (const Exc & e){cout<< e.what(); }

             }





                       .

            
             
       class Exc : exception {

            public:

                        Exc():exception() {}

                        Exc(const string& s): exception( s.c_str() ){}

                        virtual const char *what() const throw(){ return exception::what();}

        };

         class A {

                   int x;

             public:

                   A(int i):x(i){ }



                   string g(int i){

                                           if( i>x) throw Exc("Overflow");

                                           if( i<0) throw Exc("Underflow");

                                           return "Ok";

                                            }

              };

           void F(){

                          try{

                                 A a(20);

                                 cout << a.g(-20);

                                }

                           catch (const Exc * e){cout<< e->what(); }

                            catch (...){cout<<"Fatal";}

                            cout<<":)";

              }





                  

          
           
     class A {

            int x;

        public:

           A(int i):x(i){ }

           string g(int i){

                           if( i>x) throw string("Over");

                           if( i<0) throw string("Under");

                           return "Ok";

                              }

          };

           void F(){

                         try{

                              A a(20);

                              cout << a.g(-20);

                               }

                           catch (const char* e) {cout <<"Out of range";}

                           catch (const string& e){cout<< e; }

                            catch (...){cout<<"Fatal";}

                            cout<<":)";

              }





                

         
         


          class Exc : exception {

              public:

                          Exc():exception() {}

                          Exc(const string& s):exception( s.c_str() ){}

                          virtual const char *what() const throw(){ return exception::what();}

            };

            class A {

                           int x;

               public:

                           A(int i):x(i){ }



                           const string g(int i){ if( i>x) throw Exc(":(");return "Ok";}

               };

              void F(){

                             try{ cout << (A(10)).g(20); }

                             catch (const Exc & e){cout<< e.what(); }

                }







 

 
 


                   class E1 {};



      class E2 {

         public:

            explicit E2(const E1&) {}

        };

       void h(){ cout << "UE" << endl;  exit(0);}



       void g(){ E1 e; throw e; }

 

       void F() {

          set_terminate(h);

          try {  g(); }

          catch(E2&) { cout << "E2" << endl; }

          catch(...) { cout << "AE" << endl; }

        }















                     

           
            
      class A {

                  int x;

          public:

                   A(int i):x(i){ }



                    string g(int i){

                                         if( i>x) throw "Over";

                                         if( i<0) throw "Under";

                                         return "Ok";

                                         }

              };

              void F(){

                            try{

                                  A a(20);

                                  cout << a.g(-20);

                                  }

                              catch (const string &e){cout<< "Out of range"; }

                              catch(const char* &e){cout<<e;}

                              catch (...){cout<<"Fatal";}

                               cout<<":)";

                               }



















              class Exc : exception {

                public:

                         Exc():exception() {}

                         virtual const char *what() const throw(){ return "Exc";}

              };

             class A {

                        int x;

              public:

                       A(int i):x(i){ }



                     const string g(int i){ if( i>x) throw Exc(); return "Ok";}

              };

             void F(){

                             try{ cout << (A(10)).g(19); }

                            catch (Exc e){cout<< e.what(); }

                           }





                  .

          
           
     class A {

            int x;

        public:

           A(int i):x(i){ }

           string g(int i){

                           if( i>x) throw string("Over");

                           if( i<0) throw string("Under");

                           return "Ok";

                              }

          };

           void F(){

                         try{

                              A a(20);

                              cout << a.g(-20);

                               }

                           catch (const char* e) {cout <<"Out of range";}

                           catch (const string& e){cout<< e; }

                            catch (...){cout<<"Fatal";}

                            cout<<":)";

              }











                

         
         


          class Exc : exception {

              public:

                          Exc():exception() {}

                          Exc(const string& s):exception( s.c_str() ){}

                          virtual const char *what() const throw(){ return exception::what();}

            };

            class A {

                           int x;

               public:

                           A(int i):x(i){ }



                           const string g(int i){ if( i>x) throw Exc(":(");return "Ok";}

               };

              void F(){

                             try{ cout << (A(10)).g(20); }

                             catch (const Exc & e){cout<< e.what(); }

                }















 

 
 


                   class E1 {};



      class E2 {

         public:

            explicit E2(const E1&) {}

        };

       void h(){ cout << "UE" << endl;  exit(0);}



       void g(){ E1 e; throw e; }

 

       void F() {

          set_terminate(h);

          try {  g(); }

          catch(E2&) { cout << "E2" << endl; }

          catch(...) { cout << "AE" << endl; }

        }













 .

 
 


                   class E1 {};



      class E2 {

         public:

            explicit E2(const E1&) {}

        };

       void h(){ cout << "UE" << endl;  exit(0);}



       void g(){ E1 e; throw e; }

 

       void F() {

          set_terminate(h);

       try {  g(); }

       catch(E2&) { cout << "E2" << endl; }

       catch(...) { cout << "AE" << endl; }

     }











.





           class Exc : exception {

             public:

                      Exc():exception() {}

                      virtual const char *what() const throw(){ return "Exc";}

           };

          class A {

                     int x;

           public:

                    A(int i):x(i){ }



                  const string g(int i){ if( i>x) throw Exc(); return "Ok";}

           };

          void F(){

                          try{ cout << (A(10)).g(19); }

                         catch (Exc e){cout<< e.what(); }

                        }





















class Exc : exception {

public:

Exc():exception() {}

Exc(const string& s): exception( s.c_str() ){}

virtual const char *what() const throw(){ return exception::what();}

};

class A {

string x;

public:

A(string i):x(i){ }



const string& g(const string& i){if( i>x) throw Exc("Over");return x;}

};

void F(){

try{

A a("10");

cout << a.g("20");

}

            catch (const Exc & e){cout<< e.what(); }

            cout<<":)";

}



















.





                class E1 {};

|

   class E2 {

      public:

         explicit E2(const E1&) {}

     };

    void h(){ cout << "UE" << endl;  exit(0);}

|

    void g(){ E1 e; throw e; }



    void F() {

       set_terminate(h);

       try {  g(); }

       catch(E2&) { cout << "E2" << endl; }

       catch(...) { cout << "AE" << endl; }

     }
















class Exc : exception {

public:

Exc():exception() {}

Exc(const string& s): exception( s.c_str() ){}

virtual const char *what() const throw(){ return exception::what();}

};

class A {

string x;

public:

A(string i):x(i){ }



const string& g(const string& i){if( i>x) throw Exc("Over");return x;}

};

void F(){

try{

A a("10");

cout << a.g("20");

}

            catch (const Exc & e){cout<< e.what(); }

            cout<<":)";

}










       class Exc : exception {

           public:

                       Exc():exception() {}

                       Exc(const string& s):exception( s.c_str() ){}

                       virtual const char *what() const throw(){ return exception::what();}

          };

         class A {

                        int x;

              public:

                        A(int i):x(i){ }



                        const string g(int i){if( i>x) throw Exc(":(");return "Ok";}

           };

          void F(){

                         try{ cout << (A(20)).g(10); }

                         catch (const Exc & e){cout<< e.what(); }

          }






           class Exc : exception {

             public:

                      Exc():exception() {}

                      virtual const char *what() const throw(){ return "Exc";}

           };

          class A {

                     int x;

           public:

                    A(int i):x(i){ }



                  const string g(int i){ if( i>x) throw Exc(); return "Ok";}

           };

          void F(){

                          try{ cout << (A(10)).g(19); }

                         catch (Exc e){cout<< e.what(); }

                        }




    class E1 {};

     class E2 {

           public:

                   explicit E2(const E1&) {}

       };

       void g(void) { E1 e; throw e; }



        void F() {

                     try { g(); }

                      catch(E2&) { cout << "E2" << endl; }

                      catch(...) { cout << "AE" << endl; }

         }





            .

       
        
  class A {

         int x;

     public:

        A(int i):x(i){ }

        string g(int i){

                        if( i>x) throw string("Over");

                        if( i<0) throw string("Under");

                        return "Ok";

                           }

       };

        void F(){

                      try{

                           A a(20);

                           cout << a.g(-20);

                            }

                        catch (const char* e) {cout <<"Out of range";}

                        catch (const string& e){cout<< e; }

                         catch (...){cout<<"Fatal";}

                         cout<<":)";

           }











                 .

         
          
    class Exc : exception {

         public:

                     Exc():exception() {}

                     Exc(const string& s): exception( s.c_str() ){}

                     virtual const char *what() const throw(){ return exception::what();}

     };

      class A {

                int x;

          public:

                A(int i):x(i){ }



                string g(int i){

                                        if( i>x) throw Exc("Overflow");

                                        if( i<0) throw Exc("Underflow");

                                        return "Ok";

                                         }

           };

        void F(){

                       try{

                              A a(20);

                              cout << a.g(-20);

                             }

                        catch (const Exc * e){cout<< e->what(); }

                         catch (...){cout<<"Fatal";}

                         cout<<":)";

           }





                 .

         
          
    class Exc : exception {

         public:

                     Exc():exception() {}

                     Exc(const string& s): exception( s.c_str() ){}

                     virtual const char *what() const throw(){ return exception::what();}

     };

      class A {

                int x;

          public:

                A(int i):x(i){ }



                string g(int i){

                                        if( i>x) throw Exc("Overflow");

                                        if( i<0) throw Exc("Underflow");

                                        return "Ok";

                                         }

           };

        void F(){

                       try{

                              A a(20);

                              cout << a.g(-20);

                             }

                        catch (const Exc * e){cout<< e->what(); }

                         catch (...){cout<<"Fatal";}

                         cout<<":)";

           }









 






       class Exc : exception {

           public:

                       Exc():exception() {}

                       Exc(const string& s):exception( s.c_str() ){}

                       virtual const char *what() const throw(){ return exception::what();}

          };

         class A {

                        int x;

              public:

                        A(int i):x(i){ }



                        const string g(int i){if( i>x) throw Exc(":(");return "Ok";}

           };

          void F(){

                         try{ cout << (A(20)).g(10); }

                         catch (const Exc & e){cout<< e.what(); }

          }








    class A {

                  int x;

         public:

                  A(int i):x(i){ }

                   string g(int i){

                                    if( i>x) throw "Overflow";

                                    if( i<0) throw "Underflow";

                                    return "Ok";

                                         }

          };

       void F(){

                     try{

                           A a(20);

                            cout << a.g(-20);

                          }

                      catch (const string &e){cout<< "Out of range"; }

                       catch (...){cout<<"Fatal";}

                       cout<<":)";

                       }

















       class Exc : exception {

           public:

                       Exc():exception() {}

                       Exc(const string& s):exception( s.c_str() ){}

                       virtual const char *what() const throw(){ return exception::what();}

         };

         class A {

                        int x;

            public:

                        A(int i):x(i){ }



                        const string g(int i){ if( i>x) throw Exc(":(");return "Ok";}

            };

           void F(){

                          try{ cout << (A(10)).g(20); }

                          catch (const Exc & e){cout<< e.what(); }

             }




       class Exc : exception {

           public:

                       Exc():exception() {}

                       Exc(const string& s):exception( s.c_str() ){}

                       virtual const char *what() const throw(){ return exception::what();}

          };

         class A {

                        int x;

              public:

                        A(int i):x(i){ }



                        const string g(int i){if( i>x) throw Exc(":(");return "Ok";}

           };

          void F(){

                         try{ cout << (A(20)).g(10); }

                         catch (const Exc & e){cout<< e.what(); }

          }









class Exc : exception {

public:

Exc():exception() {}

Exc(const string& s): exception( s.c_str() ){}

virtual const char *what() const throw(){ return exception::what();}

};

class A {

string x;

public:

A(string i):x(i){ }



const string& g(const string& i){if( i>x) throw Exc("Over");return x;}

};

void F(){

try{

A a("10");

cout << a.g("20");

}

            catch (const Exc & e){cout<< e.what(); }

            cout<<":)";

}





 



  class A {

         int x;

     public:

        A(int i):x(i){ }

        string g(int i){

                        if( i>x) throw string("Over");

                        if( i<0) throw string("Under");

                        return "Ok";

                           }

       };

        void F(){

                      try{

                           A a(20);

                           cout << a.g(-20);

                            }

                        catch (const char* e) {cout <<"Out of range";}

                        catch (const string& e){cout<< e; }

                         catch (...){cout<<"Fatal";}

                         cout<<":)";

           }

