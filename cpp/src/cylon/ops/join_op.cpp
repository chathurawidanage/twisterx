#include "join_op.hpp"
#include "partition_op.hpp"

cylon::JoinOp::JoinOp(std::shared_ptr<CylonContext> ctx,
                      std::shared_ptr<arrow::Schema> schema,
                      std::shared_ptr<ResultsCallback> callback,
                      std::shared_ptr<JoinOpConfig> config) : Op(ctx, schema, JOIN_OP, callback) {
  auto left_partition = new PartitionOp(ctx, schema, LEFT, callback, config->GetPartitionConfig());

  left_partition->IsComplete();
  //auto right_partition = new PartitionOp(RIGHT, callback);

//  this->AddChild(left_partition);
//  this->AddChild(right_partition);
//
//  auto local_join = new LocalJoin(LOCAL_JOIN);
//
//  // left and right goes in two directions until the local join
//  for (auto rel:{LEFT, RIGHT}) {
//    auto partition = this->GetChild(rel);
//
//    auto left_shuffle = new ShuffleOp(SHUFFLE);
//    partition->AddChild(left_shuffle);
//
//    auto sort = new SortOp(SORT);
//    left_shuffle->AddChild(sort);
//
//    sort->AddChild(local_join);
//  }
}
bool cylon::JoinOp::Execute(int tag, std::shared_ptr<Table> table) {
  // pass the left tables
  this->DrainQueueToChild(LEFT, LEFT, 0);
  this->DrainQueueToChild(RIGHT, RIGHT, 1);

  return true;
}
void cylon::JoinOp::OnParentsFinalized() {
  //todo
}

cylon::JoinOpConfig::JoinOpConfig(shared_ptr<PartitionOpConfig> partition_config) : partition_config(partition_config) {

}
shared_ptr<cylon::PartitionOpConfig> cylon::JoinOpConfig::GetPartitionConfig() {
  return this->partition_config;
}