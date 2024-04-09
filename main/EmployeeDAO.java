package main;


import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;
import java.sql.DriverManager;


public class EmployeeDAO {
    private Connection connection;

    public EmployeeDAO() {
        try {
            connection = DatabaseConnection.getConnection();
            scanner = new Scanner(System.in);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    

    public void createEmployee(Employee employee) {
        String query = "INSERT INTO employees (name, age, salary) VALUES (?, ?, ?)";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, employee.getName());
            statement.setInt(2, employee.getAge());
            statement.setDouble(3, employee.getSalary());
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    public Employee getEmployeeById(int id) {
        String query = "SELECT * FROM employees WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setInt(1, id);
            try (ResultSet resultSet = statement.executeQuery()) {
                if (resultSet.next()) {
                    String name = resultSet.getString("name");
                    int age = resultSet.getInt("age");
                    double salary = resultSet.getDouble("salary");
                    return new Employee(id, name, age, salary);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null; // Employee not found
    }

    public void updateEmployee(Employee employee) {
        String query = "UPDATE employees SET name = ?, age = ?, salary = ? WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, employee.getName());
            statement.setInt(2, employee.getAge());
            statement.setDouble(3, employee.getSalary());
            statement.setInt(4, employee.getId());
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void deleteEmployee(int id) {
        String query = "DELETE FROM employees WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setInt(1, id);
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    private Scanner scanner;
    // public void handleCRUDOperations() {
    //     System.out.println("Choose operation:");
    //     System.out.println("1. Create Employee");
    //     System.out.println("2. Read Employee");
    //     System.out.println("3. Update Employee");
    //     System.out.println("4. Delete Employee");
    //     System.out.println("5. Exit");

    //     int choice = scanner.nextInt();
    //     switch (choice) {
    //         case 1:
    //             this.createEmployee(nul;
    //             break;
    //         case 2:
    //             readEmployee();
    //             break;
    //         case 3:
    //             updateEmployee();
    //             break;
    //         case 4:
    //             deleteEmployee();
    //             break;
    //         case 5:
    //             System.out.println("Exiting...");
    //             scanner.close();
    //             break;
    //         default:
    //             System.out.println("Invalid choice!");
    //             break;
    //     }
    // }

    public static void main(String[] args) {

        System.out.println("Meow");
        try{  
            Class.forName("com.mysql.jdbc.Driver");  
            Connection con= DriverManager.getConnection(  
            "jdbc:mysql://localhost:3306/mysql","root","root123");  
             
            Statement stmt=con.createStatement();  
            ResultSet rs=stmt.executeQuery("select * from emp");  
            while(rs.next())  
            System.out.println(rs.getInt(1)+"  "+rs.getString(2)+"  "+rs.getString(3));  
            con.close();  
            System.out.println("\n\n\n\n\n\nNOICEEEEEEEEE");
        }catch(Exception e){ 
            System.out.println(e.getMessage());
            System.out.println("\n\n\n\n\n\n\nFUCKKKKKKKKKKKKKKKKK");
        }  
            
        System.out.println("\n\n\n\n\n\nNOICEEEEEEEEE");
    }  
    
}
