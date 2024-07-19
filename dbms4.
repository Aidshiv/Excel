Create a row level trigger for the customers table that would fire for INSERT or UPDATE or
DELETE operations performed on the CUSTOMERS table. This trigger will display the
salary difference between the old & new Salary.
CUSTOMERS(ID,NAME,AGE,ADDRESS,SALARY)

SQL> CREATE TABLE CUSTOMERS (
  2      ID INT PRIMARY KEY,
  3      NAME VARCHAR(100),
  4      AGE INT,
  5      ADDRESS VARCHAR(255),
  6      SALARY DECIMAL(10, 2)
  7  );

Table created.

SQL> CREATE OR REPLACE TRIGGER salary_difference_trigger
  2  BEFORE INSERT OR UPDATE OR DELETE ON CUSTOMERS
  3  FOR EACH ROW
  4  DECLARE
  5      old_salary NUMBER;
  6      new_salary NUMBER;
  7  BEGIN
  8      IF INSERTING OR UPDATING THEN
  9          old_salary := NVL(:OLD.SALARY, 0);
 10          new_salary := NVL(:NEW.SALARY, 0);
 11          DBMS_OUTPUT.PUT_LINE('Salary difference: ' || (new_salary - old_salary));
 12      ELSIF DELETING THEN
 13          old_salary := NVL(:OLD.SALARY, 0);
 14          DBMS_OUTPUT.PUT_LINE('Salary before deletion: ' || old_salary);
 15      END IF;
 16  END;
 17  /

Trigger created.

SQL> SET SERVEROUTPUT ON;

SQL> INSERT INTO CUSTOMERS (ID, NAME, AGE, ADDRESS, SALARY) VALUES (1, 'John Doe', 30, '123 Main St', 50000);

1 row created.



SQL> Update customers set salary=70000 where id=1;
Salary difference: 20000

1 row updated.