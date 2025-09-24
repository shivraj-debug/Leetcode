(SELECT u.name AS results
FROM MovieRating as mr JOIN Users as u USING(user_id)
GROUP BY u.user_id
ORDER BY count(movie_id) DESC,name
LIMIT 1)
union all
(select m.title from Movies as m 
join MovieRating as mr  using(movie_id) 
where created_at between "2020-02-01" and "2020-02-29"
group by m.movie_id 
order by avg(mr.rating) desc ,title
limit 1
)