(* https://www.hackerrank.com/challenges/functions-or-not/ *)
open Core

let read_int () =
  Out_channel.(flush stdout);
  Scanf.scanf " %d" Fun.id

let () =
  let t = read_int () in
  for _t = 1 to t do
    let n = read_int () in
    let table = Hashtbl.create (module Int) in
    let ok = ref true in
    for _i = 1 to n do
      let x = read_int () in
      let y = read_int () in
      if !ok then
        match Hashtbl.find table x with
        | None -> Hashtbl.set table ~key:x ~data:y
        | Some v -> ok := v = y
      else ()
    done;
    printf "%s\n" (if !ok then "YES" else "NO")
  done
