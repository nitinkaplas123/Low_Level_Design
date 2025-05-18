Definition:
If S is a subClass of T, then objects of type T may be replaced with objects of type S without altering the correctness of the program.

OR 

Objects of a superclass should be replaceable with objects of a subclass without affecting the correctness of the program.

OR 

If a child class (subclass) replaces the parent class (superclass), the program should still work properly.

// Think of it like this:
1. If you write code using a parent class (say Shape), and later swap in a child class 
   (using the child class object in place of the parent class object) (like Circle), 
   the code should still work without errors or unexpected behavior.
2. If the subclass changes behavior in a way that breaks expectations, it violates LSP.




class T 
{
     func1();
}

class S extends T 
{
      func2();
}


class Main(){
   T obj=new T();  // its working fine 

   // then objects of type T may be replaced with objects of type S without altering the correctness of the program.
   T obj=new S(); // now if i change the subclass obj s, if its work then it means its follow lsp.
}





// When we have only parent class.

//Code1
class Notification{
    public void sendNotification(){
        System.out.println("normal notification!!");
    }
}




public class Demo{
    public static void main(String []args){
          Notification notification=new Notification();
          notification.sendNotification();
    }
}



