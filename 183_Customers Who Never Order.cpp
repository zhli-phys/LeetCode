SELECT DISTINCT Email
FROM Person 
GROUP BY Email
HAVING COUNT(Email) > 1;



SELECT Name AS 'Customers'
FROM Customers 
WHERE Id NOT IN (SELECT CustomerId FROM Orders)