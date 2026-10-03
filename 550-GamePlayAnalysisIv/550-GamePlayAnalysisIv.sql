-- Last updated: 10/3/2026, 6:52:03 PM
# Write your MySQL query statement below
With FirstLogin as(
    select  player_id,
            MIN(event_date) as first_date 
    FROM Activity
    GROUP BY player_id
)

SELECT
    ROUND((
        COUNT(a.event_date) / (SELECT COUNT(DISTINCT  player_id ) from Activity)
    ), 2) as fraction
FROM FirstLogin f
INNER JOIN Activity a
           ON  f.player_id =  a.player_id
           AND DATEDIFF(a.event_date, f.first_date) = 1

