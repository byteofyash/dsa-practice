-- Last updated: 10/3/2026, 6:52:09 PM
# Write your MySQL query statement below
select
player_id ,
event_date as first_login
from Activity
where (player_id,event_date ) IN (

    select 
    player_id,
    MIN(event_date)
    from Activity
    group by  player_id
)