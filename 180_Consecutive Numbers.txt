WITH three AS (
    SELECT Num, LEAD(Num, 1) OVER (ORDER BY Id) AS prev, LAG(Num, 1) OVER (ORDER BY Id) AS next
    FROM Logs
)
SELECT DISTINCT Num AS ConsecutiveNums
FROM three
WHERE Num = prev AND Num = next