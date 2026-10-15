select sum(subscription_fee) as num_revenue
from(
  select  subscription_fee 
  from mobile_subscribers
  where date >= '2025-03-01' and date < '2025-04-01'
  union all
  select  subscription_fee 
  from broadband_subscribers
  where date >= '2025-03-01' and date < '2025-04-01'
) as all_subscription_fee;