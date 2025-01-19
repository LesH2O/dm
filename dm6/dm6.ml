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
      
    
      

let minecart t =
  let taille = Array.length t in
  let mini = if t.(0)<0 then ref (-t.(0)) else ref (t.(0)) in
  for i = 1 to (taille-1) do
    let temp = ref (t.(i)-i) in
    if !temp <0 then ( if (-(!temp))< !mini then mini:= !temp
                       else mini := !mini )
    else ( if !temp < !mini then mini := !temp
           else mini := !mini);
  done;
  !mini;;




let premiercommepremier t =
  let let premiercommepremier t = 
  let taille = Array.length t in
  let indice = ref (-1) in 
  for i = 1 to (taille-1) do
    indice := if ((t.(i) = t.(0))&&( !indice = -1)) then i
      else !indice;
  done;
  !indice;;

premiercommepremier [| 1; 5; 8; 6; 9; 43; 2|];;
premiercommepremier [| 1; 5; 8; 6; 9; 43; 2; 1|];;
premiercommepremier [| 1; 5; 8; 6; 9; 43; 2; 1; 5; 7; 1|];;



let premiercommeavant t =
  let res = ref (-1, -1) in
  let taille = Array.length t in
  for i = 1 to (taille-1) do
    for j = 0 to (i-1) do
      res := if ((t.(i)=t.(j))&&( !res = (-1, -1))) then (i, j)
        else !res;
    done; done;
  !res;;

premiercommeavant [|1; 5; 7; 9; 6 ;8; 43; 1; 6; 1|];;
premiercommeavant [|1; 5; 7; 9; 6 ;8; 43; 11; 62|];;  