-- Last updated: 10/3/2026, 6:51:21 PM
# Write your MySQL query statement below
select s.student_id,
        s.student_name,
        sub.subject_name ,
        COUNT(e.subject_name) as attended_exams 
from Students s
CROSS JOIN Subjects sub
LEFT JOIN Examinations e
           ON s.student_id =  e.student_id
           and sub.subject_name = e.subject_name
GROUP BY s.student_id,
        s.student_name,
        sub.subject_name 
ORDER BY 
        s.student_id,
        sub.subject_name



