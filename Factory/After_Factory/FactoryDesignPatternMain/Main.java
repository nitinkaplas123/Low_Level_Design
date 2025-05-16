package Factory.After_Factory.FactoryDesignPatternMain;

import Factory.After_Factory.FactoryDesignPattern.*;

public class Main {
     public static void main(String []args){
        OperatingSystemFactory obj=new OperatingSystemFactory ();
        OS obj1=obj.getInstance("Open");
        obj1.spec();
     }
}
