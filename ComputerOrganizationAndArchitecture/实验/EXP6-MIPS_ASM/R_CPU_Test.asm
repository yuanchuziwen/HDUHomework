main:nor $1, $0, $0;
sltu $2, $2, $1;
add $3, $2, $2;
add $4, $3, $2;
add $5, $4, $3;
add $6, $5, $3;
sllv $7, $6, $2;
add $9, $5, $6;
sllv $8, $6, $9;
xor $9, $1, $8;
add $10, $9, $1;
sub $11, $8, $7;
sub $12, $7, $8;
and $13, $9, $12;
or $14, $9, $12;
or $15, $6, $7;
nor $16, $6, $7;
add $17, $7, $3;
sllv $18, $8, $17;
sllv $19, $3, $17;
sllv $20, $19, $7;
addu $21, $20, $1; # overflow
or $22, $18, $21;
add $13, $20, $22;
subu $24, $20, $22; # overflow
subu $25, $22, $20; # overflow
xor $26, $18, $1;
sltu $27, $22, $20;
sltu $28, $26, $20;
addu $28, $22, $2; # overflow
subu $30, $20, $2; # overflow
add $31, $11, $26;
