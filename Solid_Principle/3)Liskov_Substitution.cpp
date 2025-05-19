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






//Code1 -> Original Behavior
class Notification{
    public void sendNotification(){
        System.out.println("normal notification!!");
    }
}

class TextNotification extends Notification{
    public void sendNotification(){
         System.out.println("text Notification!!");
    }
}


public class Demo{
    public static void main(String []args){
          Notification notification=new Notification();
          notification.sendNotification();
    }
}



//Code2 -: Replace Parent with Child

class Notification{
    public void sendNotification(){
        System.out.println("normal notification!!");
    }
}

class TextNotification extends Notification{
    public void sendNotification(){
         System.out.println("text Notification!!");
    }
}


public class Demo{
    public static void main(String []args){
          Notification notification=new TextNotification();
          notification.sendNotification();
    }
}


Note Points-:
1. The variable type is Notification (parent class).
2. The object is TextNotification (child class).
3. You override sendNotification() in the child class.
4. So at runtime, Java calls the child's version of sendNotification().

This is dynamic method dispatch (runtime polymorphism) — and this exact scenario is what the Liskov Substitution Principle supports.




// If tomorrow i want to send the whatsApp Notification -> 


//Code:
class Notification{
    public void sendNotification(){
        System.out.println("normal notification!!");
    }
}

class TextNotification extends Notification{
    public void sendNotification(){
         System.out.println("text Notification!!");
    }
}


class WhatsAppNotification extends Notification{
    public void sendNotification(){
         System.out.println("WhatsApp Notification!!");
    }
}



public class Demo{
    public static void main(String []args){
          Notification notification=new WhatsAppNotification();
          notification.sendNotification();
    }
}



// What Does "Substitution" Mean in LSP?
In simple terms, substitution means that you can replace an object of a parent class with an object of a child class
without affecting the correctness of the program.

// So, when you substitute a Notification with a WhatsAppNotification, you're essentially saying:
"Wherever I expect a Notification object, I can also use a WhatsAppNotification object, and the program should still behave correctly."

// Key Concept: Polymorphism
This concept is very closely tied to polymorphism in object-oriented programming. Here's how it works:

1. You have a parent class (Notification), which defines the general structure.
2. You have child classes (like TextNotification and WhatsAppNotification) that extend Notification and provide 
   specific implementations for certain methods (like sendNotification()).
3. At runtime, the program automatically decides which version of the method to call, based on the actual object type, not the reference type.