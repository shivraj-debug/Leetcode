# Write your MySQL query statement below
select emp.employee_id,
emp.name,
count(emp2.employee_id) as reports_count,
round(avg(emp2.age)) as average_age 
from Employees emp2
join Employees emp
on emp2.reports_to=emp.employee_id
group by employee_id
order by employee_id