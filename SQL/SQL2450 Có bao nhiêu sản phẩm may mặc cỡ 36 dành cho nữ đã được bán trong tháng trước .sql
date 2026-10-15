select sum(QuantitySold) as total_quantity
from SalesData
where Gender = 'Women' and size = 36 and SaleDate  >= '2025-05-01' and SaleDate  < '2025-06-01'