SELECT A.Name AS Employee
FROM Employee A
JOIN Employee B
ON A.ManagerId = B.Id
WHERE A.Salary > B.Salary;