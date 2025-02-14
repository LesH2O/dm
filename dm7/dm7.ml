let mcnuggets x y =
  let rec pgcd a b =
    if a mod b = 0 then b
    else pgcd b (a mod b)
  in if (pgcd x y) = 1 then (
    if x=1 or y=1 then failwith "avec 1 c'est facile, on part a l'infini"
    else (x*y-(x+y))) (* observation sur un echantillon de beaucoup d'essais -> complexité constante *)
  else failwith "si ils sont multiples, on part a l'infini";;


mcnuggets 4 7;;
mcnuggets 1 2;;
mcnuggets 0 5;;






let existe_somme t =
  let n = Array.length t in
  let res = ref 0 in
  for i=2 to (n-1) do
    for j=1 to (i-1) do
      for k=0 to (j-1) do
        if t.(k)=t.(j)+t.(i) then res:= !res+1
        else (if t.(j)=t.(i)+t.(k) then res := !res+1
              else (if t.(i)=t.(k)+t.(j) then res := !res+1
                    else res := !res));
             
      done;
    done;
  done;
  (!res<>0);;

existe_somme [|0;0;0|];;
existe_somme [|1;2;4|];;
existe_somme [|1;3;2|];;