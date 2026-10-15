select i.location , sum(i.amount) as total_amount 
from impact_investments i
join esg_factors e on i.company_id = e.company_id
group by i.location
having sum(i.amount) > 10000000
order by total_amount desc