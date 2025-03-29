Define: 
A Singleton class is a design pattern that ensures a class has only one instance and provides a global point of access to it.


Singleton Class:
A design pattern where:
1. Only one instance of the class exists.
2. The constructor is private.   so that no one from outside the class can make different object of class A.
3. A static method (getInstance()) provides global access to that one instance.




Code:
class A 
{
     static A obj=new A();          // one instance in a class
     private A()                    // private constructor 
     {

     }

     public static A getInstance()    // global access method
     {
        return obj;
     }
}


public class Singleton{
    public static void main(String [] args) {
        A obj=A.getInstance();
      
        System.out.println(obj);
    }
}