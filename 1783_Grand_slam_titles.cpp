WITH champions AS (
    SELECT
        Wimbledon AS id
    FROM
        Championships
    UNION ALL
    SELECT
        Fr_open AS id
    FROM
        Championships
    UNION ALL
    SELECT
        US_open AS id
    FROM
        Championships
    UNION ALL
    SELECT
        Au_open AS id
    FROM
        Championships
),
counts AS (
    SELECT 
        id, COUNT(*) AS cnts
    FROM 
        champions
    GROUP BY
        id        
)
SELECT 
    counts.id as player_id, Players.player_name, counts.cnts as grand_slams_count
FROM
    counts
JOIN
    Players
ON 
    counts.id = Players.player_id