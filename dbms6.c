1)

CREATE TABLE old_roll (
  roll INT,
  name VARCHAR(10)
);



2)

CREATE TABLE new_roll (
  roll INT,
  name VARCHAR(10)
);



3)

INSERT INTO old_roll VALUES (5, 'bch');
INSERT INTO old_roll VALUES (3, 'bcd');
INSERT INTO old_roll VALUES (5, 'bch');
INSERT INTO old_roll VALUES (1, 'bc');


4)

INSERT INTO new_roll VALUES (2, 'b');
INSERT INTO new_roll VALUES (5, 'bch');
INSERT INTO new_roll VALUES (1, 'bc');



5)

SELECT * FROM old_roll;



6)

SELECT * FROM new_roll;


7)

CREATE PROCEDURE merge_roll_call_data
IS
  v_id INT;
  v_name VARCHAR(10);
  done INT DEFAULT 0;
  CURSOR cur_new_roll_call IS
    SELECT roll, name
    FROM new_roll;

BEGIN
  FOR rec IN cur_new_roll_call LOOP
    v_id := rec.roll;
    v_name := rec.name;
    SELECT COUNT(*)
    INTO done
    FROM old_roll
    WHERE roll = v_id;
    IF done = 0 THEN
      INSERT INTO old_roll (roll, name)
      VALUES (v_id, v_name);
    END IF;
  END LOOP;
  DBMS_OUTPUT.PUT_LINE('Data merged successfully.');
END;
/


8)

CALL merge_roll_call_data();


9)

SELECT * FROM old_roll;