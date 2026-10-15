SELECT ROUND(COUNT(*) * 100.0 /(SELECT COUNT(*) FROM Vaccinations WHERE city = 'Sydney'),2) AS "Female_Percentage_Sydney(%)"
FROM Vaccinations
WHERE city = 'Sydney'
 AND gender = 'Female';