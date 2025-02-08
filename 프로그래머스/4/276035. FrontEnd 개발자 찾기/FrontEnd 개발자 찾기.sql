-- 코드를 작성해주세요-- 코드를 작성해주세요

WITH FRONT_T AS (
    select sum(code) AS f_l from skillcodes
    where category = 'Front End'
    group by category
    
)

select id, email, first_name, last_name from
developers where skill_code & (select sum(code) from skillcodes where category = 'front end' group by category)
order by id