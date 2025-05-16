Definition:
As per OCP, Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification.

A class or module should be open for extension, but closed for modification.
That means:
You should be able to extend the behavior without modifying existing code.



#Which means donot change the existing code,but you can add the code to the existing code(extension).

// Real-life Analogy
// Let's understand the application of OCP in real-life with the help of power adapters. Imagine you travel from India to the UK. Your Indian charger doesn't fit into UK power sockets. Instead of buying a new charger, you use a travel adapter.

// The adapter extends your existing charger's usability (now works in UK).
// You did not modify the charger itself.
// Similarly, in code, OCP encourages adding new functionality via extension, rather than altering existing, stable code.


Real-World Example
Lets now use region-based tax calculation (e.g., India, US, UK) in an Invoicing System to explain the Open/Closed Principle. As an invoicing system grows, it must handle tax rules for different regions (the values might not be accurate):

India: GST 18%
US: Sales Tax 8%
UK: VAT 12%



New regions maybe added over time.
Bad Design - Violating OCP

// InvoiceProcessor.java
class InvoiceProcessor {
    public double calculateTotal(String region, double amount) {
        if (region.equalsIgnoreCase("India")) {
            return amount + amount * 0.18;
        } else if (region.equalsIgnoreCase("US")) {
            return amount + amount * 0.08;
        } else if (region.equalsIgnoreCase("UK")) {
            return amount + amount * 0.12;
        } else {
            return amount; // No tax for unknown region
        }
    }
}


The above code is considered a bad practice because:
// Adding a new region (e.g., Germany) requires modifying this method.
// You risk breaking existing logic while adding new functionality.
// Hard to test, maintain, or scale.
// Violates the Open/Closed Principle.






// This code follows the open close Principle using Dependency Injection.

Code:
// Tax strategy Interface
interface TaxCalculator {
    double calculateTax(double amount);
}

// Implementing Region-Specific Tax Calculators
class IndiaTaxCalculator implements TaxCalculator {
    public double calculateTax(double amount) {
        return amount * 0.18; // GST
    }
}

class USTaxCalculator implements TaxCalculator {
    public double calculateTax(double amount) {
        return amount * 0.08; // Sales Tax
    }
}

class UKTaxCalculator implements TaxCalculator {
    public double calculateTax(double amount) {
        return amount * 0.12; // VAT
    }
}


// Using dependency Injection
class Invoice {
    private double amount;
    private TaxCalculator taxCalculator;

    public Invoice(double amount, TaxCalculator taxCalculator) {
        this.amount = amount;
        this.taxCalculator = taxCalculator;
    }

    public double getTotalAmount() {
        return amount + taxCalculator.calculateTax(amount);
    }
}

// Main class
class Main {
    public static void main(String[] args) {
        double amount = 1000.0;

        Invoice indiaInvoice = new Invoice(amount, new IndiaTaxCalculator());
        System.out.println("Total (India): ₹" + indiaInvoice.getTotalAmount());

        Invoice usInvoice = new Invoice(amount, new USTaxCalculator());
        System.out.println("Total (US): $" + usInvoice.getTotalAmount());

        Invoice ukInvoice = new Invoice(amount, new UKTaxCalculator());
        System.out.println("Total (UK): £" + ukInvoice.getTotalAmount());
    }
}


Assume that now, we want to support Germany with 15% tax. 
In such a case, a simple code snippet can be introduced in the file:


class GermanyTaxCalculator implements TaxCalculator {
    public double calculateTax(double amount) {
        return amount * 0.15;
    }
}

Thats it.




How Your Code Follows OCP:
Aspect	Description
1. Extension	-: 
You can create new tax calculators like JapanTaxCalculator, CanadaTaxCalculator, etc. by simply implementing the TaxCalculator interface.

2. No Modification -:
You don’t need to modify the Invoice class or any existing tax calculator to add new tax logic.

3. Polymorphism -:
Invoice depends on the TaxCalculator interface, so different tax calculators can be injected. 
This uses dependency injection and interface-based design.


