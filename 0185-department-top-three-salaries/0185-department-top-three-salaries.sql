# Write your MySQL query statement below
select d.name as Department , e.name as Employee , e.salary as Salary from Department as d RIGHT JOIN Employee as e ON e.departmentId=d.id 
where 3 > (select count(distinct (e2.salary)) from Employee e2 where e2.salary > e.salary and e.DepartmentId=e2.DepartmentId)

