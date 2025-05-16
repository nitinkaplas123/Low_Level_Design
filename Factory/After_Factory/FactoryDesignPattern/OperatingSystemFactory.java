package Factory.After_Factory.FactoryDesignPattern;

import Factory.After_Factory.FactoryDesignPattern.*;;
public class OperatingSystemFactory 
{
   public OS getInstance(String str) 
   {
	   if(str=="Open")
	   return new Android();
	   else if(str=="Close")
	   return new IOS();
	   else 
	   return new Window();
   }
}
