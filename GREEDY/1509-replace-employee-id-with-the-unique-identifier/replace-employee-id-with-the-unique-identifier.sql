SELECT e1.unique_id, e2.name
FROM Employees e2
LEFT JOIN EmployeeUNI e1
ON e1.id = e2.id;
