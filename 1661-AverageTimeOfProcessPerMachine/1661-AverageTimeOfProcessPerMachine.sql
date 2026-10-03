-- Last updated: 10/3/2026, 6:50:49 PM
# Write your MySQL query statement below
select a1.machine_id , 
        ROUND(AVG (a2.timestamp - a1.timestamp),3) as processing_time

from Activity a1 
INNER JOIN Activity a2
            ON a1.machine_id = a2.machine_id 
            and a1.process_id = a2.process_id 
WHERE   a1.activity_type = 'start' 
        and a2.activity_type = 'end'
    GROUP BY a1.machine_id

