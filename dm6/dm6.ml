let tables n =
  if n<6 then (-1, -1)
  else let res = (if n mod 4 = 0 then ((n/4), 0)
                  else ( if n mod 4 = 3 then ((n-3)/4, 1)
                         else ( if n mod 4 = 2 then ((n-6)/4, 2)
                                else ((n-9)/4, 3)))) in 
    res;;

tables 1;;
tables 4;;
tables 22;;
tables 141;;




let q1 t =
  let cocktail tab = 
    let taille = Array.length tab in
    for k=0 to ((taille-1)/2) do
      for i=0 to (taille-2) do
        if tab.(i) > tab.(i+1) then (
          let a = tab.(i) in 
          (tab.(i) <- tab.(i+1);
           tab.(i+1) <- a));
      done;
      for i=1 to (taille-1) do
        if tab.(taille-i) < tab.(taille-i-1) then (
          let a = tab.(taille-i) in
          (tab.(taille-i) <- tab.(taille-i-1);
           tab.(taille-i-1) <- a));
      done; done;
  in cocktail t;
  t.(((Array.length t)/4)-1);;

q1 [| 1; 2; 4; 5; 6; 7; 8; 9|];;
      
    
      