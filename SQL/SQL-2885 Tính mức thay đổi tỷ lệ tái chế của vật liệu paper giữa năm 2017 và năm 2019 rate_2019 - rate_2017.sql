select (
  select recycling_rate 
  from recycling_rates
  where material = 'paper' and year = 2019
) - (
  select recycling_rate 
  from recycling_rates
  where material = 'paper' and year = 2017
)
as rate_difference;