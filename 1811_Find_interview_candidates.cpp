WITH gold AS (
    SELECT
        gold_medal AS id
    FROM 
        Contests
    GROUP BY 
        id
    HAVING
        COUNT(*) >= 3    
),
user_ids AS (
    SELECT 
        contest_id, gold_medal AS id
    FROM 
        Contests 
    UNION
    SELECT
        contest_id, silver_medal AS id
    FROM 
        Contests
    UNION
    SELECT
        contest_id, bronze_medal AS id
    FROM 
        Contests
),
three AS (
    SELECT 
        DISTINCT a.id
    FROM
        user_ids a
    WHERE
        a.id in (SELECT id FROM user_ids b WHERE a.contest_id = b.contest_id - 1)
        and a.id in (SELECT id FROM user_ids c WHERE a.contest_id = c.contest_id - 2)
),
ids AS (
    SELECT 
        DISTINCT id
    FROM
        (SELECT id FROM three
        UNION
        SELECT * FROM gold) all_ids
)
SELECT 
    Users.name, Users.mail
FROM
    Users
JOIN
    ids
ON
    Users.user_id = ids.id