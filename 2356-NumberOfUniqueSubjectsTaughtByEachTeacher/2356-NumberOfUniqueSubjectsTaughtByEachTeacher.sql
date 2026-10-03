-- Last updated: 10/3/2026, 6:50:08 PM
# Write your MySQL query statement below
SELECT 
    teacher_id,
    COUNT(DISTINCT subject_id ) as cnt
FROM Teacher
GROUP BY teacher_id 