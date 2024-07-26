
1)

CREATE TABLE Employee (
  E_id INT,
  E_name VARCHAR(10),
  Age INT,
  Salary NUMBER
);


2)

INSERT INTO Employee VALUES (1, 'John Doe', 30, 50000);
INSERT INTO Employee VALUES (2, 'Jane Smith', 35, 60000);
INSERT INTO Employee VALUES (3, 'Michael Johnson', 40, 70000);
INSERT INTO Employee VALUES (4, 'Emily Davis', 28, 45000);
INSERT INTO Employee VALUES (5, 'David Brown', 45, 80000);



3)

DECLARE
  v_E_id Employee.E_id%TYPE;
  v_E_name Employee.E_name%TYPE;
  v_Age Employee.Age%TYPE;
  v_Salary Employee.Salary%TYPE;

  CURSOR emp_cursor IS
    SELECT E_id, E_name, Age, Salary
    FROM Employee;

BEGIN
  OPEN emp_cursor;

  LOOP
    FETCH emp_cursor INTO v_E_id, v_E_name, v_Age, v_Salary;
    EXIT WHEN emp_cursor%NOTFOUND;

    DBMS_OUTPUT.PUT_LINE('Employee ID: ' || v_E_id || ', Name: ' || v_E_name || ', Age: ' || v_Age || ', Salary: ' || v_Salary);
  END LOOP;

  CLOSE emp_cursor;
END;
/