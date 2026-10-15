select distinct a.Title
from Artworks a
join Exhibitions e on e.ArtworkID = a.ArtworkID
where ExhibitionID in(
  select e2.ExhibitionID
  from Exhibitions e2
  join Artworks a2 on a2.ArtworkID = e2.ArtworkID
  where a2.Title = 'Sunflowers'
)
and a.title <> 'Sunflowers'