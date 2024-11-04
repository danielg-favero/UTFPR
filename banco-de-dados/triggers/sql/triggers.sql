create or replace function random_between(low int, high int)
	returns int
	as $$
		begin
			return floor(random() * (high - low + 1) + low);
		end;
	$$ language 'plpgsql';
		

create or replace function alterar_pessoa()
	returns trigger
	as $$
		declare
			op integer default 1;
			op2 integer default 1;
		begin
			op := random_between(1, 4);
			if(op = 1) then
					op2 := random_between(1, 11);
					if (op2 = 1) then
						new.nome := 'Cinglair';
					elsif (op2 = 2) then
						new.nome := 'Generosa';
					elsif (op = 3) then
						new.nome := 'Nísia';
					elsif (op = 4) then
						new.nome := 'Pombinnha';
					elsif (op = 5) then
						new.nome := 'Leidi';
					elsif (op = 6) then
						new.nome := 'Rivon';
					elsif (op = 7) then
						new.nome := 'Epílogo';
					elsif (op = 8) then
						new.nome := 'Soubrasil';
					elsif (op = 9) then
						new.nome := 'Recemvindo';
					elsif (op = 10) then
						new.nome := 'Saturninio';
					else
						new.nome := 'Gigle';	
					end if;
					
			elsif (op = 2) then
				op2 := random_between(1, 6);
					if (op2 = 1) then
						new.sobrenome := 'Fonfon';
					elsif (op = 2) then
						new.nome := 'Roella';
					elsif (op = 3) then
						new.nome := 'Malla';
					elsif (op = 4) then
						new.nome := 'Wasserschwein';
					elsif (op = 5) then
						new.nome := 'Waschbär';
					else
						new.nome := 'Truthahn';
					end if;
					
			elsif(op = 3) then
				new.fk_estado_civil := random_between(1, 6);
			
			else
				new.fk_nacionalidade := random_between(1, 6);	
			end if;
		
			return new;
		end;
	$$ language 'plpgsql';
		

create trigger pessoa_trigger
	before insert on pessoa
	for each row execute function alterar_pessoa();
	