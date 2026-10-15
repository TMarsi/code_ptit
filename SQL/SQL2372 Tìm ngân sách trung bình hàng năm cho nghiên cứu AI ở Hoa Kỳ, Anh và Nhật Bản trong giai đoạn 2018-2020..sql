select avg(budget) as num_budget    
from (
  select budget,year,country
  from ai_budget_usa
  where year between 2018 and 2020
  union all
  select budget,year,country
  from ai_budget_uk
  where year between 2018 and 2020
  union all
  select budget,year,country
  from ai_budget_japan
  where year between 2018 and 2020
)as all_budgets;