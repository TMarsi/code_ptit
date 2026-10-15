select p.country
from Products p
join ProductTransparency pt on pt.product_id = p.product_id
join SupplyChainViolations sc on p.country = sc.country
where num_violations >= 1 and recycled_materials  = true