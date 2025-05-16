Reference -> https://www.geeksforgeeks.org/single-responsibility-in-solid-design-principle/



// Its not Single Responsibility Principle.

public class Invoice
{
            public void AddInvoice()
            { 
                // your logic
            }

            public void DeleteInvoice()
            { 
                // your logic
            }

            public void GenerateReport()
            { 
                // your logic
            }

            public void EmailReport()
            { 
                // your logic
            }
}


After -: Its a SPA 
public class Invoice
{
            public void AddInvoice()
            {
                // your logic
            }

            public void DeleteInvoice()
            {
                // your logic
            }
}

public class Report
{

            public void GenerateReport()
            {
                // your logic
            }
}

public class Email
{
            public void EmailReport()
            {
                // your logic
            }
}




Before Code-:

public class Invoice {
    private int id;
    private String description;

    // Constructor
    public Invoice(int id, String description) {
        this.id = id;
        this.description = description;
    }

    // Invoice management logic
    public void AddInvoice() {
        System.out.println("Invoice added: ID = " + id + ", Description = " + description);
    }

    public void DeleteInvoice() {
        System.out.println("Invoice deleted: ID = " + id);
    }

    // Email logic (violates SPA)
    public void SendInvoiceEmail() {
        System.out.println("Email sent for Invoice: ID = " + id + ", Description = " + description);
    }

    // Report generation logic (violates SPA)
    public void GenerateInvoiceReport() {
        System.out.println("Report generated for Invoice: ID = " + id + ", Description = " + description);
    }
}

// Main class to demonstrate functionality
public class Main {
    public static void main(String[] args) {
        Invoice invoice = new Invoice(101, "Purchase of office supplies");

        invoice.AddInvoice();
        invoice.DeleteInvoice();
        invoice.SendInvoiceEmail();
        invoice.GenerateInvoiceReport();
    }
}




SPA Code-:

// Class responsible for Invoice data and management
public class Invoice {
    private int id;
    private String description;

    // Constructor
    public Invoice(int id, String description) {
        this.id = id;
        this.description = description;
    }

    // Getters
    public int getId() {
        return id;
    }

    public String getDescription() {
        return description;
    }

    // Invoice management logic
    public void addInvoice() {
        System.out.println("Invoice added: ID = " + id + ", Description = " + description);
    }

    public void deleteInvoice() {
        System.out.println("Invoice deleted: ID = " + id);
    }
}

// Class responsible for sending emails related to invoices
class InvoiceEmailService 
{
    public void sendInvoiceEmail(Invoice invoice) {
        System.out.println("Email sent for Invoice: ID = " + invoice.getId() + 
                           ", Description = " + invoice.getDescription());
    }
}

// Class responsible for generating reports for invoices
class InvoiceReportService 
{
    public void generateInvoiceReport(Invoice invoice) {
        System.out.println("Report generated for Invoice: ID = " + invoice.getId() + 
                           ", Description = " + invoice.getDescription());
    }
}

// Main class to demonstrate functionality
public class Main {
    public static void main(String[] args) {
        Invoice invoice = new Invoice(101, "Purchase of office supplies");

        // Invoice management
        invoice.addInvoice();
        invoice.deleteInvoice();

        // Email service
        InvoiceEmailService emailService = new InvoiceEmailService();
        emailService.sendInvoiceEmail(invoice);

        // Report service
        InvoiceReportService reportService = new InvoiceReportService();
        reportService.generateInvoiceReport(invoice);
    }
}
