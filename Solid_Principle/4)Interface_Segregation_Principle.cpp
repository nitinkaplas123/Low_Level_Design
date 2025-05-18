Definition:
Clients should not be forced to depend on interfaces they do not use.

or 

It says: "Don't force a class to depend on methods it does not use."

In Even Simpler Terms:
Dont create big, bulky interfaces with lots of unrelated methods.
Instead, break them into smaller, more specific interfaces.
That way, classes only implement what they actually need.



Example1:

// Violation of ISP: Robot is forced to implement a method it doesnt need (eat()), which breaks the principle.

interface Worker {
    void work();
    void eat();  // Not all workers need this
}


class Robot implements Worker {
    public void work() {
        System.out.println("Robot working");
    }

    public void eat() {
        // ❌ This makes no sense for a robot
        throw new UnsupportedOperationException("Robot doesn't eat!");
    }
}


// Correct :  Follows ISP
Code:

interface Workable {
    void work();
}

interface Eatable {
    void eat();
}

class Human implements Workable, Eatable {
    public void work() {
        System.out.println("Human working");
    }

    public void eat() {
        System.out.println("Human eating");
    }
}

class Robot implements Workable {
    public void work() {
        System.out.println("Robot working");
    }
}




Example 2:

// Violates the Interface Segregation Principle.
interface UberUser{
    void bookRide();
    void acceptRide();
    void startRide();
    void endRide();
    void payRide();
}

class Rider implements UberUser
{
    // here we are forcing to Rider class to implement all the methods which is in UberUser.
    // Rider -> want : 1)bookRide()  2)payRide()

    // rest 3 functions will be implements by UberDriver
}



public class Demo{
    public static void main(String []args){
         
    }
}



// Follows ISP:

interface UberRider{
    void bookRide();
    void payRide();
}

interface UberDriver
{
    void acceptRide();
    void startRide();
    void endRide();
}

class Rider implements UberRider
{
    public void bookRide()
    {
        System.out.println("book ride");
    }
    public void payRide()
    {
        System.out.println("paid to the driver");
    }
}


class Driver implements UberDriver
{
    public void acceptRide()
    {
        System.out.println("accept the ride");
    }
    public void startRide()
    {
        System.out.println("start the ride");
    }
    public void endRide()
    {
        System.out.println("end the ride");
    }
}


public class Demo{
    public static void main(String []args){
         Driver obj=new Driver();
         obj.acceptRide();
    }
}