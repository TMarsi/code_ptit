SELECT Team,AVG(Avg_As_Home) AS Avg_As_Home,AVG(Avg_As_Away) AS Avg_As_Away
FROM (SELECT HomeTeam AS Team,HomeAttendance AS Avg_As_Home,NULL AS Avg_As_Away
      FROM TeamStats
      UNION ALL
      SELECT AwayTeam AS Team,NULL AS Avg_As_Home,AwayAttendance AS Avg_As_Away
      FROM TeamStats
) AS T
GROUP BY Team
ORDER BY Team ASC;