#include <eosio/chain/block_state.hpp>
#include <eosio/chain/exceptions.hpp>

namespace eosio { namespace chain {

   block_state::block_state( const block_header_state& prev, block_timestamp_type when, bool pbft_enabled )
   :block_header_state( prev.generate_next( when, pbft_enabled) ),
    block( std::make_shared<signed_block>()  )
   {
      static_cast<block_header&>(*block) = header;
   }

   block_state::block_state( const block_header_state& prev, signed_block_ptr b, bool skip_validate_signee, bool pbft_enabled )
   :block_header_state( prev.next( *b, skip_validate_signee, pbft_enabled)), block( move(b) )
   { }



} } /// eosio::chain
