select country,sum(budget) as total_budget 
from (
  select country ,budget,year
  from ai_budget_usa
  union all
  select country ,budget,year
  from ai_budget_uk
  union all
  select country ,budget,year
  from ai_budget_japan
) as com
where year >= 2019
group by country
order by total_budget DESC;