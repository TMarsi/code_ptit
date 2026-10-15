select r.lead_researcher
from gene g
join research r on g.research_id = r.id
group by r.id,r.lead_researcher
order by count(g.id) desc
limit 1