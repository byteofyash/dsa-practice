-- Last updated: 10/3/2026, 6:51:54 PM
# Write your MySQL query statement below
select 
        activity_date as day,
        COUNT(distinct user_id ) as active_users 
from Activity
where datediff('2019-07-27', activity_date ) >=0 
       and datediff('2019-07-27', activity_date ) < 30 
group by activity_date
