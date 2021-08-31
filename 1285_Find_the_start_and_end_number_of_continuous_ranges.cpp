WITH diff AS (
    SELECT
        log_id,
        log_id - ROW_NUMBER() OVER (ORDER BY log_id) AS diff
    FROM 
        Logs
)
SELECT 
    MIN(log_id) AS start_id, 
    MAX(log_id) AS end_id
FROM 
    diff
GROUP BY
    diff.diff












WITH start AS (
    SELECT
        log_id AS start_id
    FROM
        Logs
    WHERE
        log_id - 1 NOT IN (SELECT * FROM Logs)
),
start_ AS (
    SELECT
        start_id, ROW_NUMBER() OVER (ORDER BY start_id) AS id
    FROM
        start
),
end AS (
    SELECT
        log_id AS end_id
    FROM 
        Logs
    WHERE
        log_id + 1 NOT IN (SELECT * FROM Logs)
),
end_ AS (
    SELECT
        end_id, ROW_NUMBER() OVER (ORDER BY end_id) AS id
    FROM
        end
)
SELECT 
    start_id, end_id
FROM 
    start_
JOIN
    end_
ON
    start_.id = end_.id
ORDER BY
    start_id