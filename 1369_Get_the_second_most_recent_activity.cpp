WITH ranks AS (
    SELECT
        username, activity, startDate, endDate, 
        RANK() OVER(PARTITION BY username ORDER BY startDate DESC) as ranks
    FROM 
        UserActivity
)
SELECT
    username, activity, startDate, endDate
FROM 
    ranks
WHERE 
    ranks = 2
UNION
SELECT
    username, activity, startDate, endDate
FROM 
    UserActivity
GROUP BY 
    username
HAVING
    COUNT(*) = 1









WITH ranks AS (
    SELECT
        username, activity, startDate, endDate, 
        RANK() OVER (PARTITION BY username ORDER BY startDate DESC) as ranks,
        COUNT(*) OVER (PARTITION BY username) counts
    FROM 
        UserActivity
)
SELECT
    username, activity, startDate, endDate
FROM 
    ranks
WHERE 
    ranks = 2 OR counts = 1