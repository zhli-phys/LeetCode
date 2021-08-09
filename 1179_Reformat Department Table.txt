# Write your MySQL query statement below
WITH CTE1 AS (SELECT id, revenue FROM Department WHERE month = 'Jan'),
     CTE2 AS (SELECT id, revenue FROM Department WHERE month = 'Feb'),
     CTE3 AS (SELECT id, revenue FROM Department WHERE month = 'Mar'),
     CTE4 AS (SELECT id, revenue FROM Department WHERE month = 'Apr'),
     CTE5 AS (SELECT id, revenue FROM Department WHERE month = 'May'),
     CTE6 AS (SELECT id, revenue FROM Department WHERE month = 'Jun'),
     CTE7 AS (SELECT id, revenue FROM Department WHERE month = 'Jul'),
     CTE8 AS (SELECT id, revenue FROM Department WHERE month = 'Aug'),
     CTE9 AS (SELECT id, revenue FROM Department WHERE month = 'Sep'),
     CTE10 AS (SELECT id, revenue FROM Department WHERE month = 'Oct'),
     CTE11 AS (SELECT id, revenue FROM Department WHERE month = 'Nov'),
     CTE12 AS (SELECT id, revenue FROM Department WHERE month = 'Dec')
SELECT DISTINCT D.id, 
    CTE1.revenue AS Jan_Revenue, 
    CTE2.revenue AS Feb_Revenue,
    CTE3.revenue AS Mar_Revenue, 
    CTE4.revenue AS Apr_Revenue,
    CTE5.revenue AS May_Revenue, 
    CTE6.revenue AS Jun_Revenue,
    CTE7.revenue AS Jul_Revenue, 
    CTE8.revenue AS Aug_Revenue,
    CTE9.revenue AS Sep_Revenue, 
    CTE10.revenue AS Oct_Revenue,
    CTE11.revenue AS Nov_Revenue, 
    CTE12.revenue AS Dec_Revenue
FROM Department D
LEFT JOIN CTE1
ON D.id = CTE1.id
JOIN CTE2
ON D.id = CTE2.id
JOIN CTE3
ON D.id = CTE3.id
JOIN CTE4
ON D.id = CTE4.id
JOIN CTE5
ON D.id = CTE5.id
JOIN CTE6
ON D.id = CTE6.id
JOIN CTE7
ON D.id = CTE7.id
JOIN CTE8
ON D.id = CTE8.id
JOIN CTE9
ON D.id = CTE9.id
JOIN CTE10
ON D.id = CTE10.id
JOIN CTE11
ON D.id = CTE11.id
JOIN CTE12
ON D.id = CTE12.id