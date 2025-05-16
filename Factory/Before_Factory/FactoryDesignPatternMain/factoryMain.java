package Factory.Before_Factory.FactoryDesignPatternMain;

import Factory.Before_Factory.FactoryDesignPattern.Andriod;
import Factory.Before_Factory.FactoryDesignPattern.OS;




// Here we are disclosing the object of which type. (windows or ios or android)
public class factoryMain{
    public static void main(String[] args){
         OS obj=new Andriod();
         obj.spec();
    }
}
