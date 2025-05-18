Reference -> https://www.geeksforgeeks.org/single-responsibility-in-solid-design-principle/

// Principle:

Single Responsibility Principle states that:
1. "A class should have only one reason to change."
2. This means a class should only have one job or responsibility.



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

    // 1st reason to change -> Invoice management logic
    public void AddInvoice() {
        System.out.println("Invoice added: ID = " + id + ", Description = " + description);
    }
    
    // 1st reason to change -> Invoice management logic
    public void DeleteInvoice() {
        System.out.println("Invoice deleted: ID = " + id);
    }

    // 2nd reason to change -> Email logic 
    public void SendInvoiceEmail() {
        System.out.println("Email sent for Invoice: ID = " + id + ", Description = " + description);
    }

    // 3rd reason to change -> Report generation logic 
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


// Follows Single Responsibilty Principle

// ✅ Class 1: Only holds invoice data
public class Invoice {
    private int id;
    private String description;

    public Invoice(int id, String description) {
        this.id = id;
        this.description = description;
    }

    public int getId() {
        return id;
    }

    public String getDescription() {
        return description;
    }
}

// ✅ Class 2: Manages invoice operations (add/delete)
class InvoiceManager {
    public void addInvoice(Invoice invoice) {
        System.out.println("Invoice added: ID = " + invoice.getId() +
                           ", Description = " + invoice.getDescription());
    }

    public void deleteInvoice(Invoice invoice) {
        System.out.println("Invoice deleted: ID = " + invoice.getId());
    }
}

// ✅ Class 3: Handles sending emails
class InvoiceEmailService {
    public void sendInvoiceEmail(Invoice invoice) {
        System.out.println("Email sent for Invoice: ID = " + invoice.getId() +
                           ", Description = " + invoice.getDescription());
    }
}

// ✅ Class 4: Handles report generation
class InvoiceReportService {
    public void generateInvoiceReport(Invoice invoice) {
        System.out.println("Report generated for Invoice: ID = " + invoice.getId() +
                           ", Description = " + invoice.getDescription());
    }
}

// ✅ Main class
public class Main {
    public static void main(String[] args) {
        Invoice invoice = new Invoice(101, "Purchase of office supplies");

        InvoiceManager manager = new InvoiceManager();
        manager.addInvoice(invoice);
        manager.deleteInvoice(invoice);

        InvoiceEmailService emailService = new InvoiceEmailService();
        emailService.sendInvoiceEmail(invoice);

        InvoiceReportService reportService = new InvoiceReportService();
        reportService.generateInvoiceReport(invoice);
    }
}


// Example2 


// ❌ This class violates SRP: it handles both data and printing.
class Book {
    private String title;
    private String author;

    public Book(String title, String author) {
        this.title = title;
        this.author = author;
    }

    // 1st Reason to Change: If book data changes (e.g., add publisher, pages)
    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    // 2nd Reason to Change: If we want to change how the book is printed
    public void printBook() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
    }
}

public class Main {
    public static void main(String[] args) {
        Book book = new Book("The Alchemist", "Paulo Coelho");
        book.printBook(); // SRP violation: logic and data mixed
    }
}


// Before Code follows the SPA Principle

// ✅ Book class follows SRP: only handles book data
class Book {
    private String title;
    private String author;

    public Book(String title, String author) {
        this.title = title;
        this.author = author;
    }

    // 1st Reason to Change: If book data changes (e.g., add publisher, pages)
    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }
}

// ✅ BookPrinter class follows SRP: only handles printing
class BookPrinter {

    // 2nd Reason to Change: If we want to change how the book is displayed (e.g., to HTML)
    public void printBook(Book book) {
        System.out.println("Title: " + book.getTitle());
        System.out.println("Author: " + book.getAuthor());
    }
}

public class Main {
    public static void main(String[] args) {
        Book book = new Book("The Alchemist", "Paulo Coelho");
        BookPrinter printer = new BookPrinter();
        printer.printBook(book); // SRP respected
    }
}
