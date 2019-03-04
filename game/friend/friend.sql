CREATE TABLE `role_info` (
	`id` bigint not null,
	`count` int default 0,
	`extend` blob,
	PRIMARY KEY(`id`)
);

CREATE TABLE `relation` (
	`id` bigint not null,
	`friend_id` bigint default 0,
	`type` int not null,
	PRIMARY KEY(`id`, `friend_id`)
);
