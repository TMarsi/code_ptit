select (select recycling_rate from recycling_rates where material = 'glass' and year = 2019) - (select recycling_rate from recycling_rates where material = 'glass' and year = 2018)
as rate_difference;