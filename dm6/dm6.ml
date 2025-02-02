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


let equilibre t =
	let n = Array.length t in
	let d = Hashtbl.create n in
	for i = 0 to (n-1) do
		if Hashtbl.mem d t.(i) then Hashtbl.replace d i ((Hashtbl.find d t.(i))+1)
		else Hashtbl.add d t.(i) 1
	done ;
    let a = ref 0 in
    let verif k v b = if !a=0 then(a:=v ; true && b) else (if !a=v then true && b else false) 
    in
    Hashtbl.fold verif d true ;;

assert(equilibre [|1;2;3;4|]);;
assert(not (equilibre [|1;2;3;4;4|]));;
            
let premierabsent t =  
        let taille = Array.length t in 
        if taille = 0 then 0 else (if taille = 1 then (if t.(0) = 0 then 1 else 0) else(
        let n = Array.fold_right max t 0 in
        let r = Array.make (n+1) 0 in
        for i=0 to (Array.length t -1) do (r.(t.(i))<-r.(t.(i)) +1) done;
        let tmp = ref true in
        let i = ref 0 in
        while !tmp do (
                if r.(!i) = 0 then tmp := false
                else (i := !i+1 ;if !i>n then tmp := false))
        done;
        !i));;
assert((premierabsent [||]) = 0);;
assert((premierabsent [|1|]) = 0);;
assert((premierabsent [|0|]) = 1);;
assert((premierabsent [|0;2;3|]) = 1);;
assert((premierabsent [|0;1;2|]) = 3);;

let rpz str = 
        let t = Array.make 5 0 in
        for i=0 to ((String.length str )-1) do match str.[i] with
                |'m'-> t.(0)<-t.(0) +1 
                |'M'-> t.(0)<-t.(0) +1 
                |'o'-> t.(1)<-t.(1) +1
                |'O'-> t.(1)<-t.(1) +1
                |'s'-> t.(2)<-t.(2) +1
                |'S'-> t.(2)<-t.(2) +1
                |'e'-> t.(3)<-t.(3) +1
                |'E'-> t.(3)<-t.(3) +1
                |'l'-> t.(4)<-t.(4) +1
                |'L'-> t.(4)<-t.(4) +1
                | _ -> t.(0)<-t.(0) 
        done;
        t.(3)<-t.(3)/2; t.(4)<-t.(4)/2;
        Array.fold_right min t (String.length str);;
assert(rpz "Moselle" = 1);;
assert(rpz "MosellemosELLE" = 2);;
assert(rpz "Mosele" = 0);;

let concate k v l =
        (v,k)::l;;

let decomp a = 
        let d = Hashtbl.create a in
        let x = ref a in
        let i = ref 2 in
        while !i <= !x do 
                if (!x) mod !i = 0 then (if Hashtbl.mem d !i then Hashtbl.replace d !i ((Hashtbl.find d !i)+1)
		        else Hashtbl.add d !i 1 ;
                x := !x/(!i)
        )else i := !i +1 
        done;
        Hashtbl.fold concate d [];;


assert(decomp 2 = [(1,2)]);;
(* fonction présente dans le but de voir dans quel ordre la décomposition ressort
dans l'idéal on pourrait la trier mais c'est pas demandé elle est quan meme bien décomposé 

let rec print l = match l with
    |[] -> print_char('\n')
    |(a,b)::q -> (print_int(a); print_int(b) ; print q;);;
*)
assert(decomp 12 = [(1,3);(2,2)]);;
assert(decomp 42 = [(1,3);(1,7);(1,2)]);;

type couleur = Pique | Coeur | Carreau | Trefle
type valeur = As | Roi | Dame | Valet | Val of int
type carte = Coul of valeur * couleur 

let ptcoul t n = if t > 4 then n+t-4 else n ;; 
let evalutationHL main = 
        let t = Array.make 4 0 in
        let rec compte main= 
        match main with
        | [] -> 0
        | Coul(Val a ,c)::q -> ((match c with
            | Pique -> t.(0)<-t.(0)+1
            | Coeur -> t.(1)<-t.(1)+1
            | Carreau -> t.(2) <- t.(2) +1
            | Trefle -> t.(3) <- t.(3) +1);
            compte q)
        | Coul(v,c)::q -> (
          (match c with
            | Pique -> t.(0)<-t.(0)+1
            | Coeur -> t.(1)<-t.(1)+1
            | Carreau -> t.(2) <- t.(2) +1
            | Trefle -> t.(3) <- t.(3) +1);
           match v with 
            | As -> 4+(compte q)
            | Roi -> 3+(compte q)
            | Dame -> 2+(compte q)
            | Valet -> 1+(compte q)
            | _ -> compte q
                            )
        in (compte main) + (Array.fold_right ptcoul t 0);;












